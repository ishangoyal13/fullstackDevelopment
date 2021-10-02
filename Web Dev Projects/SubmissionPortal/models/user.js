const mongoose=require('mongoose');

const user=new mongoose.Schema({
    firstName:{
       type: String,
       required:true
    },
    lastName:String,
    eno:Number,
    file:String
    },{
    versionKey:false
});

// module.exports = User = mongoose.model('user',user);
// const User = mongoose.model('USER', user);

// module.exports = User;
const Submit = new mongoose.model("Submit",user);
module.exports = Submit;