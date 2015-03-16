# my_udf_isprime
A UDF function for MySQL to check whether a number is a prime number

## Usage

After installation you can use the isprime() function just like native function. 

- Input: int number
- Return Value: 
    - `0` if the number given is not a prime number
    - `1` if the number is a prime number

**Example**

``` mysql
mysql> select help_topic_id,isprime(help_topic_id) as isprime from mysql.help_topic limit 6;
+---------------+---------+
| help_topic_id | isprime |
+---------------+---------+
|             0 |       0 |
|             1 |       1 |
|             2 |       1 |
|             3 |       1 |
|             4 |       0 |
|             5 |       1 |
+---------------+---------+
6 rows in set (0.00 sec)
```


## Install

- Download

``` bash
git clone https://github.com/cenalulu/my_udf_isprime.git
```

- Compile

#### Mac OS X

**Notice: `MYSQL_INCLUDE_DIR` Should be set to your `include` directory path under your MySQL source code prepare in step 1**

``` bash
cd my_udf_isprime
export MYSQL_INCLUDE_DIR=/data/percona-server-5.6.22-72.0/include/ 
gcc -bundle -o my_isprime.so my_isprime.c -I$MYSQL_INCLUDE_DIR
```

- Copy the Library to MYSQL Plugin DIR

Remember you MySQL plugin directory path using following command:

``` mysql
mysql [localhost] {msandbox} ((none)) > show global variables like '%plugin%';
+---------------+--------------------------------+
| Variable_name | Value                          |
+---------------+--------------------------------+
| plugin_dir    | /data/5.6.22/lib/mysql/plugin/ |
+---------------+--------------------------------+
1 row in set (0.03 sec)
```

Copy `my_isprime.so` compiled in Step2 to the path you've remembered.

``` bash
cp my_isprime.so /data/5.6.22/lib/mysql/plugin/
```

- Load into MySQL

``` mysql
mysql> {msandbox} ((none)) > DROP FUNCTION IF EXISTS isprime;
Query OK, 0 rows affected (0.01 sec)

mysql> CREATE FUNCTION isprime RETURNS INT SONAME 'my_isprime.so';
Query OK, 0 rows affected (0.00 sec)
```

