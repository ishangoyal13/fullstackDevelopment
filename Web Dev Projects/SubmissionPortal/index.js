const express=require("express");

const Submit = require("./models/user");

const app=express();






require('./db/conn');

app.use(express.json());
app.use(express.static(__dirname+'/public'));
app.use(express.urlencoded({extended:false}));
app.set("view engine","hbs");




app.post("/upload",async (req,res)=>{
    try {
        const new_user=new Submit({
            firstName:req.body.firstName,
            lastName:req.body.lastName,
            eno:req.body.eno,
            file:req.body.file
        })
        
        const register=await new_user.save();
        res.status(201).render("home")
    } catch (error) {
        res.status(400).send(error)
    }
}) 

// var name;
// app.post("/show",async (req,res)=>{
// Register.findOne({eno: req.body.Enrollment}).select('file').then((data)=>{
//      name= data;
//     console.log(name);
// })
// })




app.listen(process.env.PORT || 3003,function (req,res) {
    console.log("the serever is running")
});
app.get("/",function(req,res){
    res.render("home");
});
app.get("/index",function(req,res){
    res.render('index');
})
app.get("/search",function(req,res){
    res.render('search');
})
// app.get("/display",function(req,res){
//     res.render('search',{name:name});
// })
app.get("/show", async(req,res) => {
    Submit.find((err,docs)=>{
        if(!err){
            res.render("search",{
                list: docs
            });
        }
        else{
            console.log(err);
        }
    });
});