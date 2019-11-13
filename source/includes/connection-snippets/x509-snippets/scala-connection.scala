// begin x509 connection
import org.mongodb.scala._
import scala.collection.JavaConverters._
import com.mongodb.connection.ClusterSettings
import com.mongodb.connection.SslSettings
import org.mongodb.scala.bson.collection.mutable.Document
import org.mongodb.scala.bson.BsonString
import com.mongodb.client.model.FindOneAndUpdateOptions

object MongoDBx509 extends App {
   System.setProperty("javax.net.ssl.trustStore","client.truststore");
   System.setProperty("javax.net.ssl.trustStorePassword","password");

   System.setProperty("javax.net.ssl.keyStore", "client.keystore");
   System.setProperty("javax.net.ssl.keyStorePassword", "password");

   // null value will force mongoDB server to use DN from cert
   val credential = MongoCredential.createMongoX509Credential(null);

   val settings = MongoClientSettings.builder()
      .credential(credential)
      .applyToClusterSettings(
         (builder: ClusterSettings.Builder)
         => builder.hosts(List(new ServerAddress("localmongo1", 27017)).asJava))
      .applyToSslSettings(
         (builder : SslSettings.Builder)
         => builder.enabled(true))
      .build();

   val client : MongoClient = MongoClient(settings);

   val db : MongoDatabase = client.getDatabase("test")
   val collection : MongoCollection[org.mongodb.scala.bson.collection.mutable.Document] = db.getCollection("stuff")
   val doc = org.mongodb.scala.bson.collection.mutable.Document("scalatest" -> BsonString("OK"))
   val insertObservable = collection.insertOne(doc)

   insertObservable.subscribe(new Observer[Completed] {
      override def onNext(result: Completed): Unit = println(s"onNext: $result")
      override def onError(e: Throwable): Unit = println(s"onError: $e")
      override def onComplete(): Unit = println("onComplete")
   })

   // print post-insert _id field
   println(doc)
}
// end x509 connection