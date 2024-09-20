import React, { useState } from 'react';
import {
  View,
  Text,
  TouchableOpacity,
  StyleSheet,
  SafeAreaView
} from 'react-native';

export default function App() {
  const [expression, setExpression] = useState('');

  const handlePress = (input) => {
    if (input === 'AC') {
      setExpression('');
    } else if (input === 'CE') {
      setExpression(expression.slice(0, -1));
    } else if (input === '=') {
      try {
        let result = eval(expression.replace('x', '*').replace('%', '/100'));
        setExpression(result.toString());
      } catch (e) {
        setExpression('Error');
      }
    } else {
      setExpression(expression + input);
    }
  };

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.resultContainer}>
        <Text style={styles.resultText}>{expression || "0"}</Text>
      </View>
      <View style={styles.buttonContainer}>
        {renderButton('AC', handlePress)}
        {renderButton('CE', handlePress)}
        {renderButton('%', handlePress)}
        {renderButton('/', handlePress)}

        {renderButton('7', handlePress)}
        {renderButton('8', handlePress)}
        {renderButton('9', handlePress)}
        {renderButton('x', handlePress)}

        {renderButton('4', handlePress)}
        {renderButton('5', handlePress)}
        {renderButton('6', handlePress)}
        {renderButton('-', handlePress)}

        {renderButton('1', handlePress)}
        {renderButton('2', handlePress)}
        {renderButton('3', handlePress)}
        {renderButton('+', handlePress)}

        {renderButton('0', handlePress, { flex: 2 })}
        {renderButton('=', handlePress)}
      </View>
    </SafeAreaView>
  );
};

const renderButton = (label, onPress, customStyle = {}) => {
  return (
    <TouchableOpacity
      style={[styles.button, customStyle]}
      onPress={() => onPress(label)}
    >
      <Text style={styles.buttonText}>{label}</Text>
    </TouchableOpacity>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    backgroundColor: '#f5f5f5',
  },
  resultContainer: {
    flex: 2,
    justifyContent: 'flex-end',
    alignItems: 'flex-end',
    padding: 20,
    backgroundColor: '#fff',
  },
  resultText: {
    fontSize: 48,
    fontWeight: 'bold',
  },
  buttonContainer: {
    flex: 5,
    flexDirection: 'row',
    flexWrap: 'wrap',
    padding: 10,
    backgroundColor: '#f5f5f5',
  },
  button: {
    width: '22%',
    height: 80,
    margin: '1.5%',
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#ddd',
    borderRadius: 10,
  },
  buttonText: {
    fontSize: 24,
    fontWeight: 'bold',
  },
});
