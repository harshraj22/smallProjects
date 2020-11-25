import { StatusBar } from "expo-status-bar";
import React, { useEffect, useState } from "react";
import {
	StyleSheet,
	Text,
	View,
	TouchableOpacity,
	ScrollView,
} from "react-native";

import { Button } from "react-native-paper";

import * as SQLite from "expo-sqlite";
const db = SQLite.openDatabase("db.testDb"); // returns Database object

const TableComp = () => {
	useEffect(() => {
		db.transaction((tx) => {
			tx.executeSql(
				"CREATE TABLE IF NOT EXISTS items (id INTEGER PRIMARY KEY AUTOINCREMENT, text TEXT, count INT)"
			);
		});
	}, []);

	let [data, setData] = useState([]);

	const fetchData = () => {
		db.transaction((tx) => {
			// sending 4 arguments in executeSql
			tx.executeSql(
				"SELECT * FROM items",
				null, // passing sql query and parameters:null
				// success callback which sends two things Transaction object and ResultSet Object
				(txObj, { rows: { _array } }) => setData(_array),
				// failure callback which sends two things Transaction object and Error
				(txObj, error) => console.log("Error ", error)
			); // end executeSQL
		}); // end transaction
	};

	const newItem = () => {
		db.transaction((tx) => {
			tx.executeSql(
				"INSERT INTO items (text, count) values (?, ?)",
				["gibberish", 0],
				(txObj, resultSet) =>
					setData([
						...data,
						{ id: resultSet.insertId, text: "gibberish", count: 0 },
					]),
				(txObj, error) => console.log("Error", error)
			);
		});
	};

	async function deleteItem(id) {
		db.transaction((tx) => {
			tx.executeSql(
				"DELETE FROM items WHERE id = ? ",
				[id],
				(txObj, resultSet) => {
					let newList = [];
					if (resultSet.rowsAffected > 0) {
						newList = data.filter((data) => {
							if (data.id === id) return false;
							else return true;
						});
						setData(newList);
						console.log(`after deleting ${id} data is ${newList}`);
					}
				}
			);
		});
	}

	const increment = (id) => {
		db.transaction((tx) => {
			tx.executeSql(
				"UPDATE items SET count = count + 1 WHERE id = ?",
				[id],
				(txObj, resultSet) => {
					if (resultSet.rowsAffected > 0) {
						let newList = data.map((data) => {
							if (data.id === id) return { ...data, count: data.count + 1 };
							else return data;
						});
						setData(newList);
					}
				}
			);
		});
	};

	async function handleDelete() {
		console.log("Cleaning table....");
		let size = data.length;
		let ids = [];
		data.forEach((value, index, arr) => {
			ids.push(value.id);
		});

		for (let i = 0; i < size; i += 1) await deleteItem(ids[i]);

		console.log("cleaned item count: ", size, "\n");
	}

	return (
		<View>
			<Button
				icon="camera"
				mode="contained"
				onPress={() => {
					console.log("Inserting data...");
					newItem();
					console.log("Length of data: ", data.length, "\n");
				}}
				style={{ margin: 10 }}
			>
				Insert
			</Button>

			<Button
				icon="camera"
				mode="contained"
				onPress={() => {
					console.log("fetching data.....");
					fetchData();
					console.log("Length of data: ", data.length, "\n");
				}}
				style={{ margin: 10 }}
			>
				Fetch
			</Button>

			<Button
				icon="camera"
				mode="contained"
				onPress={() => {
					console.log("Displaying", data.length, " data.....");
					data.forEach(({ count, id, text }, index, array) => {
						console.log(
							"at index ",
							index,
							" => ",
							` count: ${count}  id: ${id}  text: ${text}`
						);
					});

					console.log("\n");
				}}
				style={{ margin: 10 }}
			>
				Show
			</Button>

			<Button
				icon="camera"
				mode="contained"
				onPress={handleDelete}
				style={{ margin: 10 }}
			>
				Clean
			</Button>
		</View>
	);
};

export default function App() {
	return (
		<View style={styles.container}>
			<Text>Testing sqlite db ! Look console (^_^)</Text>
			<TableComp />
			<StatusBar style="auto" />
		</View>
	);
}

const styles = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: "#fff",
		alignItems: "center",
		justifyContent: "center",
	},
});
