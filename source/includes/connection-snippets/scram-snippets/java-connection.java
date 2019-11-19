// begin scram connection
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoDatabase;
// ...
MongoClient mongoClient=MongoClients.create("mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority");
MongoDatabase database=mongoClient.getDatabase("test");
// end scram connection
