CREATE TABLE `md_d_pw_fund_cust_dim`(
   `cust_no` string COMMENT '客户号', 
   `fhb_hold_ppc` string COMMENT '公募非货基持仓PPC分层', 
   `gmonline_flag` string COMMENT '公募线上客群标签', 
   `aum_hold_ppc` string COMMENT 'AUM持仓PPC分层', 
   `ck_hold_ppc` string COMMENT '存款持仓PPC分层', 
   `dqlc_hold_ppc` string COMMENT '定期理财持仓PPC分层', 
   `hqlc_hold_ppc` string COMMENT '活期理财持仓PPC分层', 
   `sm_hold_ppc` string COMMENT '私募持仓PPC分层', 
   `cust_manager_offline_chnl_type` string COMMENT '管户线下渠道类型', 
   `last_30d_fund_act_flag` string COMMENT '近30天访问基金页面活跃标识', 
   `accompany_act_flag` string COMMENT '历史访问陪伴活跃标识', 
   `last_30d_accompany_act_flag` string COMMENT '近30天访问陪伴活跃标识', 
   `gmfhb_ly_hold_bal_lvl` string COMMENT '去年末公募非货基持仓金额分层', 
   `gmfhb_hold_bal_lvl` string COMMENT '当前公募非货基持仓金额分层', 
   `gmfhb_dt_hold_bal_lvl` string COMMENT '当前公募非货基定投持仓金额分层', 
   `gmfhb_dt_execute_cnt_lvl` string COMMENT '当前公募非货基定投持有正常协议数分层', 
   `gmfhb_pb_vaild_flag` string COMMENT '破冰有效户标识(T-2)', 
   `offer_gmfhb_pb_flag` string COMMENT '钩子破冰客户标识(T-2)', 
   `gmfhb_aum_rate_lvl` string COMMENT '非货基持仓和AUM的占比分层', 
   `um_self_flag` string COMMENT '管户本人客户号标识', 
   `gmfhb_vaild_hold_flag` string COMMENT '公募非货基有效持仓标识', 
   `cust_age_level` string COMMENT '客户年龄分层', 
   `sp_uv_flag` string COMMENT '当月是否访问资讯', 
   `sp_cnt_level` string COMMENT '当月资讯访问篇数分层', 
   `zb_uv_flag` string COMMENT '当月是否访问直播', 
   `zb_cnt_level` string COMMENT '当月直播访问篇数分层', 
   `dt` date COMMENT 'dt')
         ENGINE=OLAP
DUPLICATE KEY(`cust_no`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                            )
DISTRIBUTED BY HASH(`cust_no`) BUCKETS 10
PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)