#!/bin/bash

# MySQL/MariaDB 서버가 준비될 때까지 대기
if [ -d "/var/www/html/wp-admin" ]; then
	echo "Wordpress core is already download"
else
	wp core download --allow-root
	if [ -f "/var/www/html/wp-config.php" ]; then
		echo "wp-config is already create"
	else
		wp config create --dbname="$MARIADB_DB" --dbuser="$MARIADB_ID" --dbpass="$MARIADB_PW" --dbhost="$MARIADB_HOST" --url="$WP_URL" --allow-root
	fi
	wp core install --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_ID" --admin_password="$WP_ADMIN_PW " --admin_email="$WP_ADMIN_EMAIL" --skip-email --allow-root
	wp user create "$MARIADB_ID" "$WP_ADMIN_EMAIL" --user_pass="$MARIADB_PW" --role=subscriber --allow-root
	wp theme install astra --activate --allow-root
	wp plugin update --all --allow-root
fi
exec /usr/sbin/php-fpm7.4 -F