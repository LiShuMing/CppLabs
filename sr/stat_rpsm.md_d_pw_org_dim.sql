CREATE TABLE `md_d_pw_org_dim`(
   `branch_no` string COMMENT '机构号', 
   `branch_name` string COMMENT '机构名称', 
   `branch_type` string COMMENT '机构类型', 
   `branch01_no` string COMMENT '一级机构号', 
   `branch01_name` string COMMENT '一级机构名称', 
   `branch02_no` string COMMENT '二级机构号、区域号', 
   `branch02_name` string COMMENT '二级机构名称、区域名称', 
   `branch03_no` string COMMENT '三级机构号、一级分行机构号', 
   `branch03_name` string COMMENT '三级机构名称、一级分行机构名称', 
   `branch04_no` string COMMENT '四级机构号、二级分行机构号', 
   `branch04_name` string COMMENT '四级机构名称、二级分行机构名称', 
   `branch05_no` string COMMENT '五级机构号、一级支行机构号', 
   `branch05_name` string COMMENT '五级机构名称、一级支行机构名称', 
   `branch06_no` string COMMENT '六级机构号、二级支行机构号', 
   `branch06_name` string COMMENT '六级机构名称、二级支行机构名称', 
   `org_province` string COMMENT '所属省份', 
   `group_name` string COMMENT '所属组名称', 
   `sh_group_name` string COMMENT '私行中心分组名称', 
   `zh_group_name` string COMMENT '归属支行AUM规模分组', 
   `dt` date COMMENT 'dt')
         ENGINE=OLAP
DUPLICATE KEY(`branch_no`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                            )
DISTRIBUTED BY HASH(`branch_no`) BUCKETS 10
PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)