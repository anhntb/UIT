import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View } from 'react-native';

export default function App() {
  return (
    <View style={styles.container}>
      <View style={styles.dong}>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
      </View>

      <View style={styles.dong}>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
      </View>

      <View style={styles.dong}>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
      </View>

      <View style={styles.dong}>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
        <View style={styles.cot_purple}></View>
        <View style={styles.cot_red}></View>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
  },

  dong: {
    flex: 1,
    flexDirection: 'row',
  },

  cot_red: {
    flex: 1,
    backgroundColor: 'red',
  },

  cot_purple: {
    flex: 1,
    backgroundColor: 'purple',
  }
});
