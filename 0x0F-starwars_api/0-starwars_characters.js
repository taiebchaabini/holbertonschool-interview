#!/usr/bin/node
console.log()
let movieID = process.argv[2];
const request = require('request');


request({url: 'https://swapi-api.hbtn.io/api/films/' + movieID, json: true}, function (error, response, body) {
  if (response && response.statusCode == 200){
    var res = {}
    // console.log('body:', body); // Print the HTML for the Google homepage.
 
    body.characters.forEach(element => {
        let id = element.replace("https://swapi-api.hbtn.io/api/people", "");
        id = id.split("/")[1];
        request({url: element, json: true}, function(error, response, body){
            if (response && response.statusCode == 200){
                //console.log(body.name);
                res[id] = body.name;
            }
        });

    });;

    setTimeout(function(){
        body.characters.forEach(elem => {
            let id = elem.replace("https://swapi-api.hbtn.io/api/people", "");
            id = id.split("/")[1];
            console.log(res[id]);
        });
    }, 3000)
   
  } 
});

