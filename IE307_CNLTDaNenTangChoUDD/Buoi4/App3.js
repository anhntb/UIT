// Navigate Between Screens using React Navigation in React Native //
// https://aboutreact.com/react-native-stack-navigation //



import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import PageLoaihoa from './pages/PageLoaihoa';
import PageHoa from './pages/PageHoa';
import PageCtHoa from './pages/PageCtHoa';
const Stack = createNativeStackNavigator();
function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="FirstPage">
        <Stack.Screen  name="PageLoaihoa"  
        component={PageLoaihoa}
        options={{
          title: 'Trang Chủ', //Set Header Title
          headerStyle: {
            backgroundColor: '#f4511e', //Set Header color
          },
          headerTintColor: '#fff', //Set Header text color
          headerTitleStyle: {
            fontWeight: 'bold', //Set Header text style
          },
        }}   />
        <Stack.Screen   
        name="PageHoa"  
         component={PageHoa}
         options={{
          title: 'Danh Sách Hoa', //Set Header Title
          headerStyle: {
            backgroundColor: '#f4511e', //Set Header color
          },
          headerTintColor: '#fff', //Set Header text color
          headerTitleStyle: {
            fontWeight: 'bold', //Set Header text style
          },
        }}  />
        <Stack.Screen   name="PageCtHoa"  
          component={PageCtHoa} 
          options={{
            title: 'Chi Tiết Hoa', //Set Header Title
            headerStyle: {
              backgroundColor: '#f4511e', //Set Header color
            },
            headerTintColor: '#fff', //Set Header text color
            headerTitleStyle: {
              fontWeight: 'bold', //Set Header text style
            },
          }} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

export default App;