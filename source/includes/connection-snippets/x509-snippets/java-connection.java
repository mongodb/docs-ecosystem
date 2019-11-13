// begin  x509 connection
package com.java.mongodb;

import java.util.Arrays;

import org.bson.Document;

import com.mongodb.MongoClientSettings;
import com.mongodb.MongoCredential;
import com.mongodb.ServerAddress;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoIterable;

public class MyDemo {

    public static void main(String args[]) {

        System.setProperty("javax.net.ssl.trustStore", "/Users/<user>/dev/drivers/certs/v3/client.truststore");
        System.setProperty("javax.net.ssl.trustStorePassword", "<pass>");

        System.setProperty("javax.net.ssl.keyStore", "/Users/<user>/dev/drivers/certs/v3/client.keystore");
        System.setProperty("javax.net.ssl.keyStorePassword", "<pass>");

        try {
            String subject = "<your_subject>"; // CN=ChrisChoClient,OU=TestClientCertificateOrgUnit,O=TestClientCertificateOrg,L=TestClientCertificateLocality,ST=TestClientCertificateState,C=US
            MongoCredential credential = MongoCredential.createMongoX509Credential(subject);

            MongoClientSettings settings = MongoClientSettings.builder().credential(credential)
                    .applyToClusterSettings(builder -> builder.hosts(Arrays.asList(new ServerAddress("localmongo1"))))
                    .applyToSslSettings(builder -> builder.enabled(true)).build();

            MongoClient client = MongoClients.create(settings);
            client.close();
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
// end x509 connection