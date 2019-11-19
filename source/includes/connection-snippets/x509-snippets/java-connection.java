// begin x509 connection
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;

public class X509Connection {

public static void main(String args[]) {
        // Set system properties via commandline or programmatically
        System.setProperty("javax.net.ssl.keyStore", "/etc/certs/mongodb/v3/client.keystore");
        System.setProperty("javax.net.ssl.keyStorePassword", "<your_password>");
        
        String uri = "mongodb+srv://<your-x509-client-subject>@<cluster-url>/?authMechanism=MONGODB-X509";
        MongoClient client = MongoClients.create(uri);
        // ...
        client.close();
    }
}
// end x509 connection
