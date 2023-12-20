FROM postgres:latest@sha256:3fc654768ae8431e28fa326ca2998b374bb0acea7904ba4894938bf470d8ed50
COPY docker-healthcheck.sh /usr/local/bin/
HEALTHCHECK CMD ["docker-healthcheck.sh"]
