#!/bin/sh

openssl req -newkey rsa:4096 -days 30 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=IT/CN=${WP_ADMIN_ID}.42.fr" \
    -keyout "/etc/ssl/${WP_ADMIN_ID}.42.fr.key" \
    -out "/etc/ssl/${WP_ADMIN_ID}.42.fr.crt" 2>/dev/null

exec nginx -g 'daemon off;'