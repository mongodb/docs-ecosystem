import com.mongodb.ConnectionString;
import com.mongodb.MongoClientSettings;
import com.mongodb.ServerApi;
import com.mongodb.ServerApiVersion;
import com.mongodb.reactivestreams.client.MongoClient;
import com.mongodb.reactivestreams.client.MongoClients;

// ...

ServerApi serverApi = ServerApi.builder()
        .version(ServerApiVersion.V1)
        .build();

MongoClientSettings settings = MongoClientSettings.builder()
        .applyConnectionString(new ConnectionString(uri))
        .serverApi(serverApi)
        .build();

MongoClient mongoClient = MongoClients.create(settings);

// ...

