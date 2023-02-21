CREATE TABLE `md_d_pw_fund_prod_dim`(
   `prod_id` string COMMENT '产品代码（后端）', 
   `fund_daily_profit_flag` string COMMENT '日日盈产品标识', 
   `fund_gm365_flag` string COMMENT '公募365产品标识', 
   `fund_prod_managers_name` string COMMENT '基金经理人名称组', 
   `fund_pockets_type` string COMMENT '钱袋子标识', 
   `dt` date COMMENT 'dt')
         ENGINE=OLAP
DUPLICATE KEY(`prod_id`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                            )
DISTRIBUTED BY HASH(`prod_id`) BUCKETS 10
PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)