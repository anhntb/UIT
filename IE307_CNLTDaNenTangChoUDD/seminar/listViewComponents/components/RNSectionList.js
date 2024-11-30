// Example to make Section List in React Native
// https://aboutreact.com/react-native-sectionlist/

// import React in our code
import React from 'react';

// import all the components we are going to use
import {
  SafeAreaView,
  StyleSheet,
  View,
  SectionList,
  Text
} from 'react-native';

const RNSectionList = () => {
  let A = [
    {id: '1', value: 'Afghanistan'},
    {id: '2', value: 'Afghanistan'},
    {id: '3', value: 'Afghanistan'},
  ];
  let B = [
    {id: '4', value: 'Benin'},
    {id: '5', value: 'Bhutan'},
    {id: '6', value: 'Bosnia'},
    {id: '7', value: 'Botswana'},
    {id: '8', value: 'Brazil'},
    {id: '9', value: 'Brunei'},
    {id: '10', value: 'Bulgaria'},
  ];

  const FlatListItemSeparator = () => {
    return (
      //Item Separator
      <View style={styles.listItemSeparatorStyle} />
    );
  };

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.container}>
        <SectionList
          ItemSeparatorComponent={FlatListItemSeparator}
          sections={[
            {title: 'Section Head For Data A', data: A},
            {title: 'Section Head For Data B', data: B},
          ]}
          renderSectionHeader={({section}) => (
            <Text style={styles.sectionHeaderStyle}>
              {section.title}
            </Text>
          )}
          renderItem={({item}) => (
            // Item for the FlatListItems
            <Text
              style={styles.sectionListItemStyle}
              //Item Separator View
              onPress={() => alert(JSON.stringify(item))}>
              {item.value}
            </Text>
          )}
          keyExtractor={(item, index) => index}
        />
      </View>
    </SafeAreaView>
  );
};

export default RNSectionList;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    backgroundColor: 'white',
  },
  sectionHeaderStyle: {
    backgroundColor: '#CDDC89',
    fontSize: 20,
    padding: 5,
    color: '#fff',
  },
  sectionListItemStyle: {
    fontSize: 15,
    padding: 15,
    color: '#000',
    backgroundColor: '#F5F5F5',
  },
  listItemSeparatorStyle: {
    height: 0.5,
    width: '100%',
    backgroundColor: '#C8C8C8',
  },
});


import React, {useEffect, useState} from 'react';
// Import required components
import {
  SafeAreaView,
  LayoutAnimation,
  StyleSheet,
  View,
  Text,
  ScrollView,
  UIManager,
  TouchableOpacity,
  Platform,
} from 'react-native';

const ExpandableComponent = ({item, onClickFunction}) => {
  //Custom Component for the Expandable List
  const [layoutHeight, setLayoutHeight] = useState(0);

  useEffect(() => {
    if (item.isExpanded) {
      setLayoutHeight(null);
    } else {
      setLayoutHeight(0);
    }
  }, [item.isExpanded]);

  return (
    <View>
      {/*Header of the Expandable List Item*/}
      <TouchableOpacity
        activeOpacity={0.8}
        onPress={onClickFunction}
        style={styles.header}>
        <Text style={styles.headerText}>
          {item.category_name}
        </Text>
      </TouchableOpacity>
      <View
        style={{
          height: layoutHeight,
          overflow: 'hidden',
        }}>
        {/*Content under the header of the Expandable List Item*/}
        {item.subcategory.map((item, key) => (
          <TouchableOpacity
            key={key}
            style={styles.content}
            onPress={
              () => alert('Id: ' + item.id + ' val: ' + item.val)
          }>
            <Text style={styles.text}>
              {key}. {item.val}
            </Text>
            <View style={styles.separator} />
          </TouchableOpacity>
        ))}
      </View>
    </View>
  );
};