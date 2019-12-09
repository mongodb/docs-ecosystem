
// begin scram connection
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCollection;
import org.bson.Document;
import org.bson.BsonDocument;

public class X509Connection {

    public static void main(String args[]) {
        String uri = "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority";
        MongoClient client = MongoClients.create(uri);

        MongoDatabase database = client.getDatabase("testDB");
        MongoCollection<Document> collection = database.getCollection("testCol");
        BsonDocument filter = new BsonDocument();
        collection.countDocuments(filter);

        client.close();
    }
}
// end scram connection
