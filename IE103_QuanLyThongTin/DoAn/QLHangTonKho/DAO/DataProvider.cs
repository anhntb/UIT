using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLHangTonKho.DAO
{
    public class DataProvider
    {
        private string connectionStr = "Data Source=LAPTOP-BPN8GDKT;Initial Catalog=QLHangTonKho;Integrated Security=True;Encrypt=False";

        public DataTable ExecuteQuery(string query, object[] parameters = null)
        {
            DataTable data = new DataTable();

            using (SqlConnection connection = new SqlConnection(connectionStr))
            {
                connection.Open();

                SqlCommand cmd = new SqlCommand(query, connection);

                string[] listPara = query.Split(' ');
                int i = 0;
                foreach (string item in listPara)
                {
                    if (item.Contains('@'))
                    {
                        cmd.Parameters.AddWithValue(item, parameters[i]);
                        i++;
                    }
                }

                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                adapter.Fill(data);

                connection.Close();
            }

            return data;
        }

    }
}
