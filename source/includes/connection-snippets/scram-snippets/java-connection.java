
// begin scram connection
import com.mongodb.ConnectionString;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoDatabase;
import com.mongodb.MongoClientSettings;

// ...
ConnectionString connString = new ConnectionString(
    "mongodb+srv://<username>:<password>@<cluster-address>/test?w=majority"
);
MongoClientSettings settings = MongoClientSettings.builder()
    .applyConnectionString(connString)
    .retryWrites(true)
    .build();
MongoClient mongoClient = MongoClients.create(settings);
MongoDatabase database = mongoClient.getDatabase("test");
// begin scram connection