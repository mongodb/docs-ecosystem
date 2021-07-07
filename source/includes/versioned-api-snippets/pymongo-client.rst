from pymongo.mongo_client import MongoClient
from pymongo.server_api import ServerApi

# replace this with your MongoDB connection string
conn_str = "<your MongoDB Atlas connection string>"

client = pymongo.MongoClient(conn_str, server_api=ServerApi('1'), serverSelectionTimeoutMS=5000)
