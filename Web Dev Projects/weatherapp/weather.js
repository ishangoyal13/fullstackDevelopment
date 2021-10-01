const express = require('express');
const https =require('https');
const app =express();
const bodyparser= require("body-parser");
app.use(bodyparser.urlencoded({extended:true}));
app.use(express.static(__dirname + '/public'));
app.set("view engine", "ejs");


app.listen(process.env.PORT || 3004,function(){
    console.log("The server has started  ");
})


var weather;
var place;
var temperature;
var imgURL;
app.post("/",function(request,response){
    
    const apikey ="138572201aa5b4b57ae98a64a81621a0";
    var cityname=request.body.cityname;
    const url="https://api.openweathermap.org/data/2.5/weather?q="+cityname+"&appid="+apikey+"&units=metric";
    https.get(url,function(res){
        res.on("data",function(data){
           
           
           var weatherinfo=JSON.parse(data);
            weather = weatherinfo.weather[0].main;
            temperature = weatherinfo.main.temp;
            place=weatherinfo.name;
           var icon = weatherinfo.weather[0].icon;
            imgURL= "http://openweathermap.org/img/wn/"+icon+"@2x.png"
        //    response.write("<h1>"+"The weather in "+place+" is "+weather+"</h1>");
        //    response.write("The temperature in "+cityname+" is "+ temperature+"<br>");
        //    response.write("<img src="+imgURL+">");
        //    response.send();
        response.redirect('/');
        });
        
    });
    

})
// app.get("/",function(request,response){
//     response.render('index.ejs');
//     });

app.get("/",function(request,response){
    response.render('index.ejs',{weather:weather,place:place,temperature:temperature,imgURL:imgURL});
    });



 