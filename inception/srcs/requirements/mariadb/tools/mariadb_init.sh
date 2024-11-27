#!/bin/sh
if [ ! -d "/var/lib/mysql/$MARIADB_DB" ]; then
  mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal >/dev/null
  service mariadb start
  sleep 5

mysql -u root <<EOF
use mysql;
flush privileges;
create database $MARIADB_DB;
create user '$MARIADB_ID'@'%' identified by '$MARIADB_PW';
grant all privileges on $MARIADB_DB.* to '$MARIADB_ID'@'%';
flush privileges;
EOF
else
	echo "Database is already created"
fi
mysqladmin -u root --password=${MARIADB_PW} shutdown

exec mysqld --datadir=/var/lib/mysql