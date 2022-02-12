import 'package:flutter/material.dart';
import 'dart:math';

class Note extends StatelessWidget {
  final String title;
  final String description;

  Note({required this.title, required this.description});

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 100,
      width: 170,
      child: Container(
        margin: const EdgeInsets.all(10),
        color: Colors.amber,
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: IntrinsicWidth(
            child: Column(
              children: <Widget>[
                Text(
                  title,
                  style: const TextStyle(
                    fontSize: 20,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const Divider(
                  color: Colors.black,
                ),
                Text(
                  ' ${description.substring(0, min(20, description.length))}...',
                  style: const TextStyle(
                    fontSize: 12,
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
