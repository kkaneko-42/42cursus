# nginx

FROM alpine:3.15

MAINTAINER kkaneko

RUN apk add --update-cache --no-cache nginx

COPY ./nginx.conf /etc/nginx

EXPOSE 443

ENTRYPOINT /usr/sbin/nginx -g "daemon off;" -c /etc/nginx/nginx.conf
