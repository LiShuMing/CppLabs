CREATE TABLE `md_d_date_dm_dim`(
   `calendar_date` string COMMENT '日期', 
   `previous_day` string COMMENT '前一天日期', 
   `next_day` string COMMENT '后一天日期', 
   `year` string COMMENT '年份', 
   `month` string COMMENT '月份', 
   `is_holiday` string COMMENT '是否节假日', 
   `year_month` string COMMENT '年月', 
   `is_in_7days` string COMMENT '是否在7天内', 
   `is_in_30days` string COMMENT '是否在30天内', 
   `is_in_14days` string COMMENT '是否在14天内', 
   `is_in_60days` string COMMENT '是否在60天内', 
   `is_in_90days` string COMMENT '是否在90天内', 
   `is_cur_day` string COMMENT '是否本日', 
   `is_cur_week` string COMMENT '是否本周', 
   `is_cur_mon` string COMMENT '是否本月', 
   `is_cur_quat` string COMMENT '是否本季', 
   `is_cur_year` string COMMENT '是否本年', 
   `stat_date` string COMMENT '当前日期', 
   `year_days` decimal(38,2) COMMENT '年天数', 
   `now_year_days` decimal(38,2) COMMENT '截止当前年天数', 
   `is_in_5days` string COMMENT '是否在5天内', 
   `is_in_15days` string COMMENT '是否在15天内', 
   `dt` string COMMENT 'dt')
         ENGINE=OLAP
DUPLICATE KEY(`calendar_date`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                        )
DISTRIBUTED BY HASH(`calendar_date`) BUCKETS 10


PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)