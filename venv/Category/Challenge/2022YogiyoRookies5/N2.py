import spacy

nlp = spacy.load("en_core_web_sm")

def anonymize_text(sentences):
    doc=nlp(sentences)
    res=""
    ents=[(e.text,e.label_) for e in doc.ents]
    for e in ents:
        if e[1]=="PERSON":
            res+="X"*len(e[0])
        else:
            res+=str(e[0])
    return res

print(anonymize_text("Ada Lovelace was born in London"))