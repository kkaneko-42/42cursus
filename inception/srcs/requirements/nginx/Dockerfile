FROM alpine:latest

RUN apk add --update --no-cache nginx

EXPOSE 80

ENTRYPOINT /usr/sbin/nginx -g "daemon off;" -c /etc/nginx/nginx.conf
