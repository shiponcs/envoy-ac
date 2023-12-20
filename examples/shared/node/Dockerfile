FROM node:21.4-bullseye-slim@sha256:e42a19a34d91f1d9be82f60bc7a8e349171df305b5f6aefe862d44d98089d9bb as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
