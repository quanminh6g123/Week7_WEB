var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');
const bodyParser = require("body-parser");

mongoose.connect("mongodb+srv://it4409:it4409-soict@lamdb-crud.qd3s7vv.mongodb.net/?retryWrites=true&w=majority" , {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});
mongoose.connection.on("connected", () => {
  console.log("Connected to MongoDB");
});
let userSchema = mongoose.Schema({
  title: {
    type:String,
  },
  body: {
    type:String,
  },
});

let blog = mongoose.model('blog', userSchema);

/* GET home page. */
router.get('/', async function(req, res, next) {
  try {
    const data = await blog.find({});
    console.log('LIST:', data);
    res.render('index', { title: 'NMQ', data: data });
  } catch (error) {
    console.log('error:', error);
    res.send(error);
  }
});

router.get('/form-add',async function(req, res){
  res.render('form-add',{});
});

router.post('/add',async function(req, res, next){
  const u = new blog(req.body);
  try{
    await u.save();

    res.redirect('/');
  }catch(error){
    res.status(500).send(error);
  }
});
router.get('/form-update/:id',async function(req, res,next){
  const id = req.params.id;

  try {
    console.log(id)
    const data = await blog.findById(id);
    res.render('form-update',{ blog:data });
  } catch (error) {
    next(error);
  }
});
router.post('/update', async function(req, res, next) {
  const id = req.params.id;
  try {
    const data = await blog.findByIdAndUpdate(req.body._id, req.body);
    res.redirect('/');
    console.log(req.body._id);
  } catch (error) {
    console.log(error);
  }
});



module.exports = router;
