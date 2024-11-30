from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

# Membuat chatbot
chatbot = ChatBot('MyBot')

# Melatih chatbot dengan corpus
trainer = ChatterBotCorpusTrainer(chatbot)
trainer.train('chatterbot.corpus.indonesia')  # Anda bisa memilih bahasa lain

# Fungsi untuk berkomunikasi dengan chatbot
while True:
    try:
        user_input = input("You: ")
        response = chatbot.get_response(user_input)
        print("Bot: ", response)
    except (KeyboardInterrupt, EOFError, SystemExit):
        break
