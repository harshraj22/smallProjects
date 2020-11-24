import { StatusBar } from "expo-status-bar";
import React from "react";
import {
	StyleSheet,
	Text,
	View,
	FlatList,
	Image,
	TouchableHighlight,
	ScrollView,
} from "react-native";
import { createStackNavigator } from "@react-navigation/stack";
import { NavigationContainer } from "@react-navigation/native";
import { Button } from "react-native-paper";

const Stack = createStackNavigator();

const data = [
	{
		title: "The Halloween",
		description:
			"  This is the first movie describing the Halloween festival. This is the first movie describing the Halloween festival. This is the first movie describing the Halloween festival. This is the first movie describing the Halloween festival.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night.This is the first movie describing the Halloween festival. It talks about two ghosts meeting people on halloween night. This is the next level work being done.  ",
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
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
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
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
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
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
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
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
	{
		title: "Other",
		description:
			"This movie is about a scientific experiment, that accidently turns a human into venom. ",
		img: require("./assets/favicon.png"),
	},
];

const DetailScreen = (props) => {
	return (
		<View style={[styles.container, styles.show]}>
			<FlatList
				style={[
					{
						flexDirection: "column",
						flex: 1,
						width: "100%",
					},
					styles.show,
				]}
				data={data}
				keyExtractor={(item, index) => index.toString()}
				renderItem={({ index, item }) => {
					let title = item.title;
					let description = item.description;
					let img = item.img; // require(val.img);
					// console.log(item, typeof item);

					return (
						<TouchableHighlight
							style={[styles.button, { flexDirection: "row", padding: 7 }]}
							key={index}
						>
							<View
								style={[
									{
										flex: 1,
										flexDirection: "row",
										height: 50,
										justifyContent: "flex-start",
									},
									styles.show,
								]}
							>
								<Image
									source={img}
									style={[
										{
											borderRadius: 95,
											width: "20%",
											height: "100%",
											resizeMode: "cover",
											marginHorizontal: 10,
										},
										styles.show,
									]}
								/>
								<View style={[{ width: "70%", height: "100%" }, styles.show]}>
									<Button
										key={index}
										icon="book"
										color="#d2691e"
										mode="contained"
										style={{
											height: "100%",
											alignContent: "flex-start",
											justifyContent: "center",
											borderRadius: 30,
											padding: 10,
										}}
										onPress={() =>
											props.navigation.navigate("other", {
												title: title,
												description: description,
												img: img,
											})
										}
									>
										{title}
									</Button>
								</View>
							</View>
						</TouchableHighlight>
					);
				}}
			/>
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
			<ScrollView>
				<TouchableHighlight style={[styles.items, { alignItems: "center" }]}>
					<Image source={img} style={{ width: 300, height: 300 }}></Image>
				</TouchableHighlight>
				<Text style={styles.items}> {description}</Text>
			</ScrollView>
		</View>
	);
};

export default function App() {
	return (
		<NavigationContainer>
			<Stack.Navigator>
				<Stack.Screen
					name="details"
					component={DetailScreen}
					options={{
						title: "Movie List",
						headerStyle: { backgroundColor: "lemonchiffon" },
					}}
				/>
				<Stack.Screen
					name="other"
					component={OtherScreen}
					options={{
						title: "Movie Description",
						headerStyle: { backgroundColor: "linen" },
					}}
				/>
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
		flexDirection: "column",
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
	show: {
		borderColor: "black",
		// borderWidth: 1,
	},
});
