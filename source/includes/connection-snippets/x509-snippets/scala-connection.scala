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
}
// end x509 connection