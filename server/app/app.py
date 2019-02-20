from flask import Flask, request, session, g, url_for, abort, render_template, make_response, redirect, app
import math, re, sys
#from werkzeug.contrib.cache import MemcachedCache	
#from __init__ import buf
import redis
from flask_caching import Cache



#cache = Cache(config={'CACHE_TYPE': 'simple'})	
#from werkzeug.contrib.cache import SimpleCache
#cache = SimpleCache()


app = Flask(__name__)
#cache.init_app(app)
app.debug = 1
application = app



def get_resource_as_string(name, charset='utf-8'):
    with app.open_resource(name) as f:
        return f.read().decode(charset)

app.jinja_env.globals['get_resource_as_string'] = get_resource_as_string
r = redis.StrictRedis(host='localhost', port=6379, db=0)

@app.route("/")
def home():
	return render_template('index.html')


@app.route("/auth", methods=['GET','POST'])
def auth():
	ses_id = 0
	if request.method == 'POST':
		ses_id = request.form.get('ses_id') 
		return render_template('getframe.html',ses_id=ses_id)
	return render_template('auth.html')

@app.route("/getframe", methods=['GET','POST']) # API для веб-просмотра (html + js)
def getframe(): #TODO передавать параметр ID сессии 
	#TODO читать строку из кеша, а не из константы
	#return cache.get("frame")
	#frame = cache.get("frame")
	#if 'frame' in c2:
		#frame2 = c2['frame']
		#return c2['frame']
	#else:
	ses_id = request.args.get('ses_id') 
	if ses_id == '3232':
		if "{}".format(r.get('check'))=="b'1'":
			r.set('check',0)
			return r.get('frame')
		else:
			return "0"
	else:
		return "0"


	
	#return render_template('getframe.html')



@app.route("/setframe", methods=['POST']) # API для стримера  TODO параметры:ID сессии и ID стримера 
def setframe():
	#cache.clear()
	#print(request.header)
	#return "Received"
	#data= request.data
	#frame_from_streamer = (request.form)f #TODO распарсить что присылает стример и прочитаь фрейм
	#cache.set("frame",request.data, timeout=50 * 60)
	#TODO проверить существует ли сессия
	if request.data==r.get('frame'):
		r.set('check',0)
	else:
		r.set('frame', request.data)
		r.set('check','1')
		


	#c2['frame'] = request.data
	#return cache.get("frame") # todo ответы стримеру
	#return c2['frame']
	return "cache: {}".format(r.get('frame'))


if __name__ == "__main__":
	app.run(debug=True)