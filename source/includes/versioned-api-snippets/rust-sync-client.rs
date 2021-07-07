use mongodb::{bson::doc, sync::Client, options::{StreamAddress, ClientOptions, ServerApi, ServerApiVersion}};

fn main() -> mongodb::error::Result<()> {
    // Parse your connection string into an options struct
    let mut options = ClientOptions::builder()
        .hosts(vec![
            StreamAddress {
                hostname: "localhost".to_string(),
                port: Some(27017),
            }
        ])
        .build();

    let server_api = ServerApi::builder()
        .version(ServerApiVersion::Version1)
        .strict(false)
        .build();
    options.server_api = Some(server_api);

    let client = Client::with_options(options)?;

    // ...
}
