CREATE TABLE `md_d_pw_user_dim`(
   `user_id` string COMMENT '员工号', 
   `user_name` string COMMENT '员工姓名', 
   `user_status` string COMMENT '员工状态', 
   `user_type` string COMMENT '员工类型', 
   `org_id` string COMMENT '所属机构', 
   `channel_id` string COMMENT '渠道号', 
   `channel_name` string COMMENT '渠道名称', 
   `dept_no` string COMMENT '部门编号', 
   `dept_name` string COMMENT '部门名称', 
   `team_id` string COMMENT '团队ID', 
   `team_name` string COMMENT '团队名称', 
   `center_id` string COMMENT '私行中心', 
   `center_name` string COMMENT '私行中心名称', 
   `user_level` string COMMENT '职级', 
   `in_date` string COMMENT '入司时间', 
   `out_date` string COMMENT '离职时间', 
   `user_sex` string COMMENT '性别', 
   `user_age` string COMMENT '年龄', 
   `birthday` string COMMENT '生日', 
   `birthplace` string COMMENT '出生地点', 
   `nativeplace` string COMMENT '籍贯', 
   `address` string COMMENT '地址', 
   `postal` string COMMENT '邮编', 
   `eng_name` string COMMENT '英文名', 
   `pab_code` string COMMENT '平安员工编号', 
   `post_date` string COMMENT '入职时间', 
   `posn_dt` string COMMENT '入岗日期', 
   `mar_status` string COMMENT '婚姻状况', 
   `mar_status_desc` string COMMENT '婚姻状况描述', 
   `school` string COMMENT '毕业院校', 
   `edu_lvl_achv` string COMMENT '最高学历', 
   `nation` string COMMENT '民族', 
   `nation_desc` string COMMENT '民族描述', 
   `party_id` string COMMENT '政治面貌', 
   `party_desc` string COMMENT '政治面貌描述', 
   `lc_quali_flag` string COMMENT '是否有理财销售资质', 
   `fund_quali_flag` string COMMENT '是否有基金销售资质', 
   `ins_quali_flag` string COMMENT '是否有保险销售资质', 
   `is_branch_flag` string COMMENT '是否归属分支行', 
   `is_pb_flag` string COMMENT '是否归属私行中心', 
   `nw_sw` string COMMENT '内外勤类别', 
   `nw_sw_desc` string COMMENT '内外勤中文描述', 
   `agent_um` string COMMENT '人员UM号', 
   `realy_gh_flag` string COMMENT '真实管户标识', 
   `valid_gh_flag` string COMMENT '有效管户标识', 
   `realy_zy_flag` string COMMENT '真实职员标识', 
   `dt` date COMMENT 'dt')
ENGINE=OLAP
DUPLICATE KEY(`user_id`)
   PARTITION BY RANGE(`dt`)
                        (
                            PARTITION `p230201` VALUES LESS THAN ("2023-02-01"),
                            PARTITION `p230302` VALUES LESS THAN ("2023-02-02"),
                            PARTITION `p230303` VALUES LESS THAN ("2023-02-03")
                            )
DISTRIBUTED BY HASH(`user_id`) BUCKETS 10

PROPERTIES (
"replication_num" = "1",
"in_memory" = "false",
"storage_format" = "DEFAULT"
)