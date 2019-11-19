// begin x509 connection
import java.util.Arrays;
import org.bson.Document;
import com.mongodb.MongoClientSettings;
import com.mongodb.MongoCredential;
import com.mongodb.ServerAddress;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoIterable;

public class X509Connection {

    public static void main(String args[]) {

        System.setProperty("javax.net.ssl.keyStore", "/etc/certs/mongodb/v3/client.keystore");
        System.setProperty("javax.net.ssl.keyStorePassword", "<your_password>");

        try {
            String subject = "<your_subject>"; // x509 client certificate subject
            MongoCredential credential = MongoCredential.createMongoX509Credential(subject);

            MongoClientSettings settings = MongoClientSettings.builder().credential(credential)
                    .applyToClusterSettings(builder -> builder.hosts(Arrays.asList(new ServerAddress("<cluster-url>"))))
                    .applyToSslSettings(builder -> builder.enabled(true)).build();

            MongoClient client = MongoClients.create(settings);
            client.close();
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
// end x509 connection
