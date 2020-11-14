#!/usr/bin/node
let movieID = process.argv[2];

const request = require('request-promise');
var res = []

async function getCharacter(input) {
       try {
          return await request({url: input, json: true});
       } catch (e) {
          console.error(e)
       }  
 }

request({url: 'https://swapi-api.hbtn.io/api/films/' + movieID, json: true}).then(body => {

    body.characters.forEach(link => {
        console.log(link);
        res.push(getCharacter(link));
    })

    res.forEach(elem => { 
        elem.then(character => { console.log(character.name) } );
    })
   
        
});


