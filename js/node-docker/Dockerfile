FROM node:8

WORKDIR /app

COPY package*.json index.js /app/
RUN npm install

EXPOSE 8080

CMD ["node", "index.js"]