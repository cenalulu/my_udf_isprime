# my_udf_isprime
A UDF function for MySQL to check whether a number is a prime number


## Install

1. Download

``` bash
git clone https://github.com/cenalulu/my_udf_isprime.git
```

2. Compile

### for Mac OS X

**Notice: `MYSQL_INCLUDE_DIR` Should be set to your `include` directory path under your MySQL source code prepare in step 1**

``` bash
cd my_udf_isprime
export MYSQL_INCLUDE_DIR=/data/percona-server-5.6.22-72.0/include/ 
gcc -bundle -o my_isprime.so my_isprime.c -I$MYSQL_INCLUDE_DIR
```

3. Copy the Library to MYSQL Plugin DIR

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
