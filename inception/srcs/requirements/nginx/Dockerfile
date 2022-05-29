# nginx

FROM alpine:3.15

RUN apk add --update-cache --no-cache nginx

EXPOSE 443

COPY ./nginx.conf /etc/nginx

ENTRYPOINT /usr/sbin/nginx -g "daemon off;" -c /etc/nginx/nginx.conf
