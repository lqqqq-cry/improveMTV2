use mysql_ssb_1;

-- set persist=1;
DROP TABLE IF EXISTS dwdate;
create table dwdate (
                        d_datekey          int,
                        d_date             char(18),
                        d_dayofweek        char(9),
                        d_month            char(9),
                        d_year             int,
                        d_yearmonthnum     int,
                        d_yearmonth        char(7),
                        d_daynuminweek     int,
                        d_daynuminmonth    int,
                        d_daynuminyear     int,
                        d_monthnuminyear   int,
                        d_weeknuminyear    int,
                        d_sellingseason    varchar(12),
                        d_lastdayinweekfl  int,
                        d_lastdayinmonthfl int,
                        d_holidayfl        int,
                        d_weekdayfl        int,
                        primary key (d_datekey)
);
DROP TABLE IF EXISTS supplier;
create table supplier (
                          s_suppkey int,
                          s_name    char(25),
                          s_address varchar(25),
                          s_city    char(10),
                          s_nation  char(15),
                          s_region  char(12),
                          s_phone   char(15),
                          primary key (s_suppkey)
);
DROP TABLE IF EXISTS customer;
create table customer (
                          c_custkey    int,
                          c_name       varchar(25),
                          c_address    varchar(25),
                          c_city       char(10),
                          c_nation     char(15),
                          c_region     char(12),
                          c_phone      char(15),
                          c_mktsegment char(10),
                          primary key (c_custkey)
);
DROP TABLE IF EXISTS part;
create table part (
                      p_partkey   int,
                      p_name      varchar(22),
                      p_mfgr      char(6),
                      p_category  char(7),
                      p_brand    char(9),
                      p_color     varchar(11),
                      p_type      varchar(25),
                      p_size      int,
                      p_container char(10),
                      primary key (p_partkey)
);
DROP TABLE IF EXISTS lineorder;
create table lineorder (
                           lo_orderkey      int,
                           lo_linenumber    int,
                           lo_custkey       int,
                           lo_partkey       int,
                           lo_suppkey       int,
                           lo_orderdate     int,
                           lo_orderpriority char(15),
                           lo_shippriority  char(1),
                           lo_quantity      int,
                           lo_extendedprice numeric(18, 2),
                           lo_ordtotalprice numeric(18, 2),
                           lo_discount      int,
                           lo_revenue       numeric(18, 2),
                           lo_supplycost    numeric(18, 2),
                           lo_tax           int,
                           lo_commitdate    int,
                           lo_shipmode      char(10),
                           primary key (lo_orderkey, lo_linenumber)
);
-- COPY customer  from 'customer.tbl'   DELIMITER '|';
-- COPY dwdate    from 'date.tbl'       DELIMITER '|';
-- COPY part      from 'part.tbl'       DELIMITER '|';
-- COPY supplier  from 'supplier.tbl'   DELIMITER '|';
-- COPY lineorder from 'lineorder.tbl'  DELIMITER '|';

load data infile '/var/lib/mysql-files/lineorder.tbl' into table lineorder fields terminated by '|' lines terminated by '|\n';	

load data infile '/var/lib/mysql-files/supplier.tbl' into table supplier fields terminated by '|' lines terminated by '|\n';

load data infile '/var/lib/mysql-files/customer.tbl' into table customer fields terminated by '|' lines terminated by '|\n';

load data infile '/var/lib/mysql-files/part.tbl' into table part fields terminated by '|' lines terminated by '|\n';

load data infile '/var/lib/mysql-files/date.tbl' into table dwdate fields terminated by '|' lines terminated by '|\n';
