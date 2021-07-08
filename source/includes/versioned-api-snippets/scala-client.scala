import com.mongodb.{ServerApi, ServerApiVersion}
import org.mongodb.scala._

// ...

    // replace this with your MongoDB connection string
    val uri = "<your MongoDB Atlas connection string>"

    val mongoClientSettings = MongoClientSettings.builder().applyConnectionString(ConnectionString(uri))
      .serverApi(ServerApi.builder().version(ServerApiVersion.V1).build())
      .build()

    val mongoClient = MongoClient(mongoClientSettings)

