CREATE TABLE ebooks (
                          MD5 TEXT PRIMARY KEY,
                          inLib BOOLEAN DEFAULT '0',
                          uploaded INTEGER DEFAULT '0',
                          toUpload INTEGER DEFAULT '1'
                        );|
CREATE INDEX ebooks_MD5 on ebooks(MD5);
						  
