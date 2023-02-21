CREATE TABLE `md_d_pw_prod_fund_buy_order_stat`(
 `serial_no` string COMMENT '订单流水号',
 `tx_type_desc` string COMMENT '交易类型(区分普通购买或定投购买)',
 `trans_type` string COMMENT '交易类型(区分首发、定投、持盈)',
 `cust_no` string COMMENT '客户号',
 `prod_id` string COMMENT '产品长编码(后端)',
 `tx_date` date COMMENT '下单日期(日期格式)',
 `cfm_date` date COMMENT '成交日期(日期格式)',
 `tx_amt_rmb` decimal(34,9) COMMENT '购买金额(折人民币)',
 `asso_serial` string COMMENT '定投协议号',
 `cfm_amt_rmb` decimal(33,9) COMMENT '成交金额(折人民币)',
 `bank_charge` decimal(16,2) COMMENT '手续费',
 `add_upd_saler` string COMMENT '推荐人UM（考虑补录）',
 `trade_dt_flag` string COMMENT '交易式定投标识Y/N',
 `fh_org_id` string COMMENT '战报分行机构(补录,推荐人>管户>客户归属)',
 `online_offline_flag` string COMMENT '线上线下远程标识(不考虑补录)',
 `tx_dt` string COMMENT '下单日期(字符格式)',
 `cfm_dt` string COMMENT '成交日期(字符格式)',
 `scheme_flag` string COMMENT '组合标识Y/N',
 `yxjj_buy_flag` string COMMENT '作为优选产品下单被购买标识Y/N',
 `time_on_offline_flag` string COMMENT '弃用',
 `tx_dt_month` string COMMENT '交易日期(月)',
 `online_offline_add_flag` string COMMENT '线上线下远程标识(考虑补录)',
 `fh_org_id_bak` string COMMENT '战报分行机构(不补录,推荐人>管户>客户归属)',
 `zh_org_id_bak` string COMMENT '战报支行机构(不补录,仅推荐人非pb)',
 `sh_gh_org_id_bak` string COMMENT '战报支行机构(不补录,推荐人>管户>客户归属)',
 `sh_org_id_bak` string COMMENT '战报私行机构(不补录，推荐人pb>管户人pb)',
 `gr_org_id_bak` string COMMENT '战报个人机构(不补录，仅推荐人)',
 `zh_org_id` string COMMENT '战报支行机构(补录,仅推荐人非pb)',
 `sh_gh_org_id` string COMMENT '战报私行机构(补录，推荐人pb>管户人pb)',
 `sh_org_id` string COMMENT '战报私行机构(补录，推荐人pb)',
 `gr_org_id` string COMMENT '战报个人机构(补录，仅推荐人)',
 `jzxt_fund_flag` string COMMENT '家族信托投配公募标识',
 `cfm_serial_flag` string COMMENT '成交订单标识Y/N',
 `add_upd_saler_bak` string COMMENT '增加推荐人(不补录)',
 `his_org_id_pms` string COMMENT '时点客户归属行机构',
 `buy_sign_m_flag` string COMMENT '当月购买当月签订标识',
 `fund_pockets_type` string COMMENT '公募钱袋子类型',
 `fund_trans_mode` string COMMENT '区分直连和非直连类型',
 `sell_code_channel_name` string COMMENT '分销渠道名称', 
   `dt` date COMMENT 'dt')
         ENGINE=OLAP
DUPLICATE KEY(`serial_no`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                            )
DISTRIBUTED BY HASH(`serial_no`) BUCKETS 10
PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)