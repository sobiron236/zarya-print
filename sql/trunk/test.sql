BEGIN TRANSACTION;CREATE TABLE sync (prn INTEGER,usr INTEGER, atr INTEGER);create table input    (id INTEGER primary key autoincrement,i_name text,i_mandat_s INTEGER, i_mandat_c INTEGER);create table s_part   (id INTEGER primary key autoincrement,display_val text);create table c_part   (id INTEGER primary key autoincrement,display_val text);create table printers (id INTEGER primary key autoincrement,prn_name text,mandat_s_id INTEGER,mandat_c_id INTEGER, prn_desc text,FOREIGN KEY(mandat_s_id) REFERENCES s_part(id),FOREIGN KEY(mandat_c_id) REFERENCES c_part(id) );create table users    (id INTEGER primary key autoincrement,usr_name text,mandat_s_id INTEGER,mandat_c_id INTEGER,FOREIGN KEY(mandat_s_id) REFERENCES s_part(id),FOREIGN KEY(mandat_c_id) REFERENCES c_part(id) );create table rel_prn_usr (prn_id INTEGER,usr_id INTEGER,FOREIGN KEY(prn_id) REFERENCES printers(id),FOREIGN KEY(usr_id) REFERENCES users(id));COMMIT;