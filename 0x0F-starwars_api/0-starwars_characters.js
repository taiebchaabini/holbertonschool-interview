#!/usr/bin/node
const movieID = process.argv[2];
const request = require('request');

request({ url: 'https://swapi-api.hbtn.io/api/films/' + movieID, json: true }, function (error, response, body) {
  if (error) {
    return;
  }
  if (response && response.statusCode === 200) {
    const res = {};

    body.characters.forEach(element => {
      let id = element.replace('https://swapi-api.hbtn.io/api/people', '');
      id = id.split('/')[1];
      request({ url: element, json: true }, function (error, response, body) {
        if (error) {
          return;
        }
        if (response && response.statusCode === 200) {
          res[id] = body.name;
        }
      });
    });

    setTimeout(function () {
      body.characters.forEach(elem => {
        let id = elem.replace('https://swapi-api.hbtn.io/api/people', '');
        id = id.split('/')[1];
        console.log(res[id]);
      });
    }, 3000);
  }
});
