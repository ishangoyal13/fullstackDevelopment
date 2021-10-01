
const express = require('express');
const app =express();
const bodyParser= require("body-parser");
app.use(express.static(__dirname + '/public'));
app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));

app.listen(process.env.PORT || 3003, function() {
    console.log("The server is running!");
    

    })

 

var task = [];
 
var complete = [];
 
app.post("/addtask", function(req, res) {
var newTask = req.body.newtask;
task.push(newTask);
res.redirect("/");
});


 
app.post("/removetask", function(req, res) {
var completeTask = req.body.check;
//check for the “typeof” the different completed task, then add into the complete task
if (typeof completeTask === "string") {
complete.push(completeTask);
//check if the completed task already exits in the task when checked, then remove it
task.splice(task.indexOf(completeTask), 1);
} else if (typeof completeTask === "object") {
for (var i = 0; i < completeTask.length; i++) {
complete.push(completeTask[i]);
task.splice(task.indexOf(completeTask[i]), 1);
}
}
res.redirect("/");
});

app.post("/clear", function(req, res){
     task = [];
 
     complete = [];
    res.redirect("/");
   
});

    let date_ob= new Date();
    let date=("0"+date_ob.getDate()).slice(-2);
    let month=("0"+(date_ob.getMonth()+1)).slice(-2);
    let year =date_ob.getFullYear();
    console.log(date+"-"+month+"-"+year);
    var Fdate=date+"-"+month+"-"+year;

 
app.get("/", function(req, res) {
res.render("index", { task: task, complete: complete,Fdate: Fdate});
});
 














