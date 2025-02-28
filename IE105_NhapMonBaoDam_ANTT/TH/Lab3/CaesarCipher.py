import tkinter as tk
from tkinter import messagebox

def caesar_encrypt(plaintext, key):
    encrypted_text = ""
    for char in plaintext:
        if char.isalpha():
            shift = 65 if char.isupper() else 97
            encrypted_text += chr((ord(char) - shift + key) % 26 + shift)
        else:
            encrypted_text += char
    return encrypted_text

def caesar_decrypt(ciphertext, key):
    decrypted_text = ""
    for char in ciphertext:
        if char.isalpha():
            shift = 65 if char.isupper() else 97
            decrypted_text += chr((ord(char) - shift - key) % 26 + shift)
        else:
            decrypted_text += char
    return decrypted_text

def brute_force_decrypt(ciphertext):
    result = ""
    for key in range(1, 26):
        decrypted_text = caesar_decrypt(ciphertext, key)
        result += f"Key {key}: \n{decrypted_text}\n\n\n"
    return result

def encrypt_text():
    try:
        key = int(key_entry.get())
        plaintext = text_input.get("1.0", "end-1c")
        if key < 1 or key > 25:
            messagebox.showerror("Error", "Key must be between 1 and 25")
            return
        encrypted_text = caesar_encrypt(plaintext, key)
        result_text.delete(1.0, tk.END)  # Xóa nội dung cũ
        result_text.insert(tk.END, f"Encrypted Text:\n{encrypted_text}")
    except ValueError:
        messagebox.showerror("Error", "Please enter a valid key")

def decrypt_text():
    try:
        key = int(key_entry.get())
        ciphertext = text_input.get("1.0", "end-1c")
        if key < 1 or key > 25:
            messagebox.showerror("Error", "Key must be between 1 and 25")
            return
        decrypted_text = caesar_decrypt(ciphertext, key)
        result_text.delete(1.0, tk.END)  # Xóa nội dung cũ
        result_text.insert(tk.END, f"Decrypted Text:\n{decrypted_text}")
    except ValueError:
        messagebox.showerror("Error", "Please enter a valid key")

def brute_force():
    ciphertext = text_input.get("1.0", "end-1c")
    brute_force_result = brute_force_decrypt(ciphertext)
    result_text.delete(1.0, tk.END)  # Xóa nội dung cũ
    result_text.insert(tk.END, f"Brute-force Decryption Results:\n{brute_force_result}")

# Create the main window
root = tk.Tk()
root.title("Caesar Cipher")

# Create the UI components
instruction_label = tk.Label(root, text="Enter text and key for Caesar Cipher Encryption/Decryption")
instruction_label.pack(pady=10)

text_input_label = tk.Label(root, text="Enter text:")
text_input_label.pack()

text_input = tk.Text(root, height=10, width=70)
text_input.pack(padx=50, pady=5)

key_label = tk.Label(root, text="Enter key (1-25):")
key_label.pack()

key_entry = tk.Entry(root)
key_entry.pack(pady=5)

# Buttons for encryption, decryption, and brute-force
encrypt_button = tk.Button(root, text="Encrypt", command=encrypt_text)
encrypt_button.pack(pady=5)

decrypt_button = tk.Button(root, text="Decrypt", command=decrypt_text)
decrypt_button.pack(pady=5)

brute_force_button = tk.Button(root, text="Brute-force Decrypt", command=brute_force)
brute_force_button.pack(pady=5)

# Frame for the Scrollbar and Text widget
result_frame = tk.Frame(root)
result_frame.pack(pady=10)

# Create a Scrollbar
scrollbar = tk.Scrollbar(result_frame)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

# Create a Text widget to display results
result_text = tk.Text(result_frame, height=18, width=70, wrap=tk.WORD, yscrollcommand=scrollbar.set)
result_text.pack(side=tk.LEFT, fill=tk.BOTH, pady=10)
scrollbar.config(command=result_text.yview)

# Run the application
root.mainloop()
