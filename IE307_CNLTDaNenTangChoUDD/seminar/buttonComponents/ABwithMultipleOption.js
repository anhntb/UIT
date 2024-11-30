// Floating Action Button with Multiple Option in React Native
// https://aboutreact.com/react-native-action-button/

// import React in our code
import React from 'react';

// import all the components we are going to use
import { SafeAreaView, StyleSheet, View, Text } from 'react-native';

//Import ActionButton
import ActionButton from 'react-native-action-button';

//Import Icon for the ActionButton
import Icon from 'react-native-vector-icons/Ionicons';

const App = () => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.container}>
        <Text style={styles.titleStyle}>
          Example of Floating Action Button
          with Multiple Option in React Native
        </Text>
        <Text style={styles.textStyle}>
          Click on Action Button to see Alert
        </Text>
        <ActionButton buttonColor="rgba(231,76,60,1)">
          {/*Inner options of the action button*/}
          {/*Icons here
             https://infinitered.github.io/ionicons-version-3-search/
           */}
          <ActionButton.Item
            buttonColor="#9b59b6"
            title="Add to Watch Later"
            onPress={() => alert('Added to watch later')}>
            <Icon
              name="md-eye"
              style={styles.actionButtonIcon}
            />
          </ActionButton.Item>
          <ActionButton.Item
            buttonColor="#3498db"
            title="Add to Favourite"
            onPress={() => alert('Added to favourite')}>
            <Icon
              name="md-star"
              style={styles.actionButtonIcon}
            />
          </ActionButton.Item>
          <ActionButton.Item
            buttonColor="#1abc9c"
            title="Share"
            onPress={() => alert('Share Post')}>
            <Icon
              name="md-share-alt"
              style={styles.actionButtonIcon}
            />
          </ActionButton.Item>
        </ActionButton>
      </View>
    </SafeAreaView>
  );
};

export default App;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'white',
    padding: 10,
  },
  titleStyle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    padding: 10,
  },
  textStyle: {
    fontSize: 16,
    textAlign: 'center',
    padding: 10,
  },
  actionButtonIcon: {
    fontSize: 20,
    height: 22,
    color: 'white',
  },
});