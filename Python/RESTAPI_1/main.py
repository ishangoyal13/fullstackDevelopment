from flask import Flask;
from flask_restful import Api, Resource, reqparse, abort, fields, marshal_with
from flask_sqlalchemy import SQLAlchemy

# init api
app = Flask (__name__)
api = Api (app)
# /tmp/database means tmp in same directory
app.config ['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy (app)

# defining models
class VideoModel (db.Model):
	id = db.Column (db.Integer, primary_key = True)
	name = db.Column (db.String(100), nullable = False)
	views = db.Column (db.Integer, nullable =  False)
	likes = db.Column (db.Integer, nullable =  False)

	def _repr_ (self):
		# f string only works in 3.6 and above
		return f"Video(name={name}, views={views}, likes={likes})"

# do only once
#db.create_all()

# creating a dict
#names = {"tim": {"age": 19, "gender" : "male"},
#		"bill" : {"age" : 70, "gender" : "male"}}
#
# making resource
#class HelloWorld (Resource):
#	# to handle get request, pull etc
#	def get (self, name):
#		# this what happens when get is send to url
#		return names [name]
#		# returning as json format becuase serializable
#
#	def post (self):
#
#		return {"data": "Posted!"}

# new request handler object according to guildlines
video_put_args = reqparse.RequestParser ()
video_put_args.add_argument ("name", type = str, help = "Name of the video is required", required = True)
video_put_args.add_argument ("views", type = int, help = "Views of the video", required = True)
video_put_args.add_argument ("likes", type = int, help = "Likes of the video", required = True)

# for patch
video_update_args = reqparse.RequestParser ()
video_update_args.add_argument ("name", type = str, help = "Name of the video is required", required = False)
video_update_args.add_argument ("views", type = int, help = "Views of the video", required = False)
video_update_args.add_argument ("likes", type = int, help = "Likes of the video", required = False)

# how serialized
# db model to result model something
resource_fields = {
	'id': fields.Integer,
	'name': fields.String,
	'views': fields.Integer,
	'likes': fields.Integer
}
#videos = {}

#def abort_if_video_id_doesnt_exit (video_id):
#	if video_id not in videos:
#		abort(404, message = "Video id is not valid...")
#
#def abort_if_video_exists (video_id):
#	if video_id in videos:
#		abort (409, message = "Video already exits with that ID...")

class Video (Resource):

	# this makes any method seriazed
	@marshal_with (resource_fields)
	def get (self, video_id):
		# abort_if_video_id_doesnt_exit (video_id)
		result = VideoModel.query.filter_by (id = video_id).first()
		if not result:
			abort (404, message = "Could not find video with that ID...")
		return result	

	@marshal_with (resource_fields)
	def put (self, video_id):
		# argumnet parsis to find what fields are important
		# bad method for put
		#print (request.form ["likes"])
		#print (request.form)

		#abort_if_video_exists (video_id)
		#args = video_put_args.parse_args ()
		#videos [video_id] = args;
		# , for return code, by default is 200
		#return videos [video_id], 201	

		args = video_put_args.parse_args ()
		result = VideoModel.query.filter_by (id = video_id).first()
		if result:
			abort (409, message = "Video id taken...")

		video = VideoModel (id = video_id, name = args ['name'], views = args ['views'], likes = args ['likes'])
		db.session.add (video)
		db.session.commit ()
		return video, 201

	# update
	# prob not best method
	@marshal_with (resource_fields)
	def patch (self, video_id):
		args = video_update_args.parse_args ()
		result = VideoModel.query.filter_by (id = video_id).first ()

		if not result:
			abort (404, message = "Video doesnt exist, cannot update")

		# by default we get none
		if args ['name']:
			result.name = args ['name']
		if args ['views']:
			result.views = args ['views']
		if args ['likes']:
			result.likes = args ['likes']

		db.session.commit ()

		return result

	# the names is similar to request becuase common practice
	def delete (self, video_id):
		abort_if_video_id_doesnt_exit (video_id)
		del videos [video_id]
		# 204 means deleted successfully
		return '', 204


api.add_resource (Video, "/video/<int:video_id>")		

# defining the root 
# <> for defining parameter type
#api.add_resource (HelloWorld, "/helloworld/<string:name>")
# / stands for default url		

# debug false for production
if __name__ == "__main__":
	app.run (debug = True)