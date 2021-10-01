
const mongoose = require('mongoose');
mongoose.connect("mongodb+srv://new_user:admin@cluster0.gusc1.mongodb.net/myFirstDatabase?retryWrites=true&w=majority", {
     useNewUrlParser: true, 
     useUnifiedTopology: true,
  
    
 }).then(()=>{
    console.log("db connected");

 }).catch((e)=>{
   console.log(e);
 })


