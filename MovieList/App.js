import { StatusBar } from "expo-status-bar";
import React from "react";
import {
	StyleSheet,
	Text,
	View,
	Button,
	FlatList,
	Image,
	TouchableHighlight,
} from "react-native";
import { createStackNavigator } from "@react-navigation/stack";
import { NavigationContainer } from "@react-navigation/native";

const Stack = createStackNavigator();

const data = [
	{
		title: "The Halloween",
		description:
			"This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.",
		img: require("./data/images/loss.png"),
	},
	{
		title: "The Neighbours",
		description:
			"This movie is all about strange neighbours that shift to the city, and the mess they create, not knowing its consequences.",
		img: require("./assets/favicon.png"),
	},
	{
		title: "Venom",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
];

const DetailScreen = (props) => {
	return (
		<View style={styles.container}>
			{
				<FlatList
					data={data}
					renderItem={(val) => {
						// console.log(val);
						let index = val.index;
						val = val.item;
						let title = val.title;
						let description = val.description;
						let img = val.img; // require(val.img);

						return (
							<>
								{/* <Image source={val.img} style={{ width: 10, height: 10 }} /> */}
								<TouchableHighlight style={styles.button} key={index}>
									<Button
										key={index}
										color="#d2691e"
										title={val.title}
										onPress={() =>
											props.navigation.navigate("other", {
												title: val.title,
												description: val.description,
												img: val.img,
											})
										}
									/>
								</TouchableHighlight>
							</>
						);
					}}
				/>
			}
		</View>
	);
};

// Displays One Movie details
const OtherScreen = (props) => {
	// const [title, description, img] = props.route.params;
	const title = props.route.params.title;
	const description = props.route.params.description;
	const img = props.route.params.img;

	return (
		<View style={[styles.descriptionPageContainer, { alignItems: "center" }]}>
			<Text
				style={[
					styles.items,
					{ fontSize: 40, textDecorationLine: "underline" },
				]}
			>
				{title}
			</Text>
			<TouchableHighlight style={[styles.items, { alignItems: "center" }]}>
				<Image source={img} style={{ width: 300, height: 300 }}></Image>
			</TouchableHighlight>
			<Text style={styles.items}> {description}</Text>
		</View>
	);
};

export default function App() {
	return (
		<NavigationContainer>
			<Stack.Navigator>
				<Stack.Screen name="details" component={DetailScreen} />
				<Stack.Screen name="other" component={OtherScreen} />
			</Stack.Navigator>
		</NavigationContainer>
	);
}

const styles = StyleSheet.create({
	button: {
		margin: 3,
	},
	container: {
		flex: 1,
		flexDirection: "row",
		flexWrap: "wrap",
		backgroundColor: "dodgerblue",
		justifyContent: "space-around",
		padding: 20,
	},
	descriptionPageContainer: {
		flex: 1,
		flexDirection: "column",
		backgroundColor: "dodgerblue",
		alignContent: "center",
		padding: 20,
	},
	items: {
		alignContent: "center",
		fontWeight: "200",
		padding: 20,
	},
});
