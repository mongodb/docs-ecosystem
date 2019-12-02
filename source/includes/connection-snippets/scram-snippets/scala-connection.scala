// begin scram connection
import org.mongodb.scala._
import com.mongodb.connection.ClusterSettings
import org.mongodb.scala.bson.collection.mutable.Document
import org.mongodb.scala.bson.BsonString

object MongoDBx509 extends App {

   val uri: String = "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority&streamType=netty"
   val client: MongoClient = MongoClient(uri)
   val database: MongoDatabase = client.getDatabase("testDB");
   val collection: MongoCollection[Document] = database.getCollection("testCol");

   val docCount = collection.countDocuments();
   println(docCount);
}
// end scram connection